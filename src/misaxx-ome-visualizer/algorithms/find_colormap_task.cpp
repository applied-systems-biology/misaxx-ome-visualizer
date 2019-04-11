/**
 * Copyright by Ruman Gerst
 * Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
 * https://www.leibniz-hki.de/en/applied-systems-biology.html
 * HKI-Center for Systems Biology of Infection
 * Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
 * Adolf-Reichwein-Straße 23, 07745 Jena, Germany
 *
 * This code is licensed under BSD 2-Clause
 * See the LICENSE file provided with this code for the full license.
 */

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
    std::unordered_set<int> label_colors;
    for(size_t i = 0; i < images.size(); ++i) {
        auto input_access = images.at(i).access_readonly();
        if(input_access.get().type() == CV_32S) {
            for(int y = 0; y < input_access.get().rows; ++y) {
                const int *row = input_access.get().ptr<int>(y);
                for(int x = 0; x < input_access.get().cols; ++x) {
                    label_colors.insert(row[x]);
                }
            }
        }
    }

    if(!label_colors.empty()) {
        colormap attachment;

        cv::Mat hsv_in(1,1,CV_8UC3);
        cv::Mat bgr_out(1,1,CV_8UC3);

        hsv_in.at<cv::Vec3b>()[1] = 255;
        hsv_in.at<cv::Vec3b>()[2] = 255;

        for(int color : label_colors) {
            // Generate a color for this label
            double hue = (std::abs(color) % 256) / 255.0;
            hsv_in.at<cv::Vec3b>()[0] = static_cast<uchar>(hue * 180);
            cv::cvtColor(hsv_in, bgr_out, cv::COLOR_HSV2BGR);

            // Set into recoloring map
            attachment.data[color] = bgr_out.at<cv::Vec3b>(0);
        }

        // Color background black
        attachment.data[0] = cv::Vec3b(0,0,0);
        images.attach(std::move(attachment));
    }
}
