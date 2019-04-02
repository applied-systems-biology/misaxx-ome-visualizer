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

#include "visualize_task.h"
#include <opencv2/opencv.hpp>
#include <cv-toolbox/ReadableBMatTypes.h>
#include <cv-toolbox/toolbox/toolbox_semantic_convert.h>
#include <cv-toolbox/toolbox/toolbox_statistics.h>
#include <cv-toolbox/toolbox/toolbox_recoloring.h>
#include <cv-toolbox/recoloring_map.h>
#include <misaxx-ome-visualizer/attachments/colormap.h>
#include <misaxx-ome-visualizer/module_interface.h>

using namespace misaxx_ome_visualizer;
using namespace misaxx;


void visualize_task::create_parameters(misa_parameter_builder &t_parameters) {

}

void visualize_task::work() {
    auto input_access = m_input.access_readonly();
    auto output_access = m_output.access_write();

    if(input_access.get().type() == CV_32S) {
//        auto histogram = cv::toolbox::statistics::get_histogram<int>(input_access.get());
//        const auto keys = histogram.get_keys();
//        cv::recoloring_hashmap<int, cv::Vec3b> recoloring_map;
//
//        cv::Mat hsv_in(1,1,CV_8UC3);
//        cv::Mat bgr_out(1,1,CV_8UC3);
//
//        hsv_in.at<cv::Vec3b>()[1] = 255;
//        hsv_in.at<cv::Vec3b>()[2] = 255;
//
//        for(size_t i = 0; i < keys.size(); ++i) {
//            // Generate a color for this label
//            double hue = i * 1.0 / keys.size();
//            hsv_in.at<cv::Vec3b>()[0] = static_cast<uchar>(hue * 180);
//            cv::cvtColor(hsv_in, bgr_out, cv::COLOR_HSV2BGR);
//
//            // Set into recoloring map
//            recoloring_map.set_recolor(keys.at(i), bgr_out.at<cv::Vec3b>(0));
//        }
//
//        recoloring_map.set_recolor(0, cv::Vec3b(0,0,0));

        const auto attachment = get_module_as<module_interface>()->m_input.get_attachment<colormap>();

        // Apply recoloring
        cv::Mat result { input_access.get().rows, input_access.get().cols, CV_8UC3, cv::Scalar::all(0) };
        cv::toolbox::recolor(input_access.get(), result, attachment.data);

//        cv::imshow("test", result);
//        cv::waitKey(0);

        output_access.set(std::move(result));
    }
    else if(input_access.get().type() == CV_8U) {
        cv::Mat result { };
        cv::cvtColor(input_access.get(), result, cv::COLOR_GRAY2BGR);
        output_access.set(std::move(result));
    }
    else if(input_access.get().channels() == 1) {
        auto as_grayscale = cv::toolbox::semantic_convert::to_grayscale8u(input_access.get());
        cv::Mat result { };
        cv::cvtColor(input_access.get(), result, cv::COLOR_GRAY2BGR);
        output_access.set(std::move(result));
    }
    else {
        throw std::runtime_error("Unsupported OpenCV type " + std::to_string(input_access.get().type()));
    }
}

