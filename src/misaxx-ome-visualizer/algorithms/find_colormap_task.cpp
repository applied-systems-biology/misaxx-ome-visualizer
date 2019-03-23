//
// Created by ruman on 23.03.19.
//

#include <misaxx-ome-visualizer/attachments/colormap.h>
#include <misaxx/ome/accessors/misa_ome_tiff.h>
#include <cv-toolbox/toolbox/toolbox_statistics.h>
#include <misaxx-ome-visualizer/module_interface.h>
#include <cv-toolbox/histogram.h>
#include "find_colormap_task.h"

using namespace misaxx;
using namespace misaxx_ome_visualizer;

void misaxx_ome_visualizer::find_colormap_task::create_parameters(misaxx::misa_parameter_builder &t_parameters) {

}

void misaxx_ome_visualizer::find_colormap_task::work() {

    misaxx::ome::misa_ome_tiff images = get_module_as<module_interface>()->m_input;
    cv::hashmap_histogram<int> histogram;
    for(size_t i = 0; i < images.size(); ++i) {
        auto input_access = images.at(i).access_readonly();
        if(input_access.get().type() == CV_32S) {
            cv::toolbox::statistics::update_histogram(input_access.get(), histogram);
        }
    }

    if(!histogram.empty()) {
        const auto keys = histogram.get_keys();
        cv::recoloring_hashmap<int, cv::Vec3b> recoloring_map;

        cv::Mat hsv_in(1,1,CV_8UC3);
        cv::Mat bgr_out(1,1,CV_8UC3);

        hsv_in.at<cv::Vec3b>()[1] = 255;
        hsv_in.at<cv::Vec3b>()[2] = 255;

        for(size_t i = 0; i < keys.size(); ++i) {
            // Generate a color for this label
            double hue = i * 1.0 / keys.size();
            hsv_in.at<cv::Vec3b>()[0] = static_cast<uchar>(hue * 180);
            cv::cvtColor(hsv_in, bgr_out, cv::COLOR_HSV2BGR);

            // Set into recoloring map
            recoloring_map.set_recolor(keys.at(i), bgr_out.at<cv::Vec3b>(0));
        }

        recoloring_map.set_recolor(0, cv::Vec3b(0,0,0));

        colormap attachment;
        attachment.data = std::move(recoloring_map);
        images.attach(std::move(attachment));
    }
}
