//
// Created by ruman on 23.03.19.
//

#pragma once

#include <misaxx/core/attachments/misa_locatable.h>
#include <cv-toolbox/recoloring_map.h>
#include <opencv2/opencv.hpp>

namespace misaxx_ome_visualizer {
    struct colormap : public misaxx::misa_locatable {
        cv::recoloring_hashmap<int, cv::Vec3b> data;

        void from_json(const nlohmann::json &t_json) override;

        void to_json(nlohmann::json &t_json) const override;

        void to_json_schema(misaxx::misa_json_schema_property &t_schema) const override;

        std::string get_documentation_name() const override;

        std::string get_documentation_description() const override;

    protected:
        void build_serialization_id_hierarchy(std::vector<misaxx::misa_serialization_id> &result) const override;
    };
}



