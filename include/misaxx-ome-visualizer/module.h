#include <misaxx/core/misa_module.h>
#include <misaxx-ome-visualizer/module_interface.h>

namespace misaxx_ome_visualizer {
    struct module : public misaxx::misa_module<module_interface> {
        using misaxx::misa_module<module_interface>::misa_module;

        void create_blueprints(blueprint_list &t_blueprints, parameter_list &t_parameters) override;
        void build(const blueprint_builder &t_builder) override;
    };
}
