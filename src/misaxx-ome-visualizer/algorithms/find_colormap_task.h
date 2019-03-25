//
// Created by ruman on 23.03.19.
//

#pragma once

#include <misaxx/core/misa_task.h>

namespace misaxx_ome_visualizer {
    struct find_colormap_task : public misaxx::misa_task {

        using misaxx::misa_task::misa_task;

        void work() override;

        void create_parameters(misaxx::misa_parameter_builder &t_parameters) override;
    };
}



