#include <misaxx-ome-visualizer/module.h>
#include <src/misaxx-ome-visualizer/algorithms/visualize_task.h>

using namespace misaxx;
using namespace misaxx_ome_visualizer;

void module::create_blueprints(misa_dispatcher::blueprint_list &t_blueprints,
                               misa_dispatcher::parameter_list &t_parameters) {
    t_blueprints.add(create_blueprint<visualize_task>("visualize"));
}

void module::build(const misa_dispatcher::blueprint_builder &t_builder) {

    auto module = get_module_as<module_interface>();
    for(size_t i = 0; i < module->m_input.size(); ++i) {
        visualize_task &task = t_builder.build<visualize_task>("visualize");
        task.m_input = module->m_input.at(i);
        task.m_output = module->m_output.at(i);
    }

}
