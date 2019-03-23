//
// Created by ruman on 23.03.19.
//

#include "misaxx-ome-visualizer/attachments/colormap.h"

void misaxx_ome_visualizer::colormap::from_json(const nlohmann::json &t_json) {
    misa_locatable::from_json(t_json);
}

void misaxx_ome_visualizer::colormap::to_json(nlohmann::json &t_json) const {
    misa_locatable::to_json(t_json);
}

void misaxx_ome_visualizer::colormap::to_json_schema(misaxx::misa_json_schema_property &t_schema) const {
    misa_locatable::to_json_schema(t_schema);
}

std::string misaxx_ome_visualizer::colormap::get_documentation_name() const {
    return "Recoloring map";
}

std::string misaxx_ome_visualizer::colormap::get_documentation_description() const {
    return "Contains information on which label is assigned to which color";
}

void misaxx_ome_visualizer::colormap::build_serialization_id_hierarchy(
        std::vector<misaxx::misa_serialization_id> &result) const {
    misa_locatable::build_serialization_id_hierarchy(result);
    result.emplace_back(misaxx::misa_serialization_id("misa-ome-visualizer", "attachments/colormap"));
}
