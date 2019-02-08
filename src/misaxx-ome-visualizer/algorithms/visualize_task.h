//
// Created by rgerst on 08.02.19.
//

#pragma once

#include <misaxx/core/misa_task.h>
#include <misaxx/ome/accessors/misa_ome_plane.h>

namespace misaxx_ome_visualizer {
    struct visualize_task : public misaxx::misa_task {
        using misaxx::misa_task::misa_task;

        misaxx::ome::misa_ome_plane m_input;
        misaxx::ome::misa_ome_plane m_output;

        void work() override;

        void create_parameters(misaxx::misa_parameter_builder &t_parameters) override;
    };
}




