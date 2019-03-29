#include <misaxx-ome-visualizer/module.h>
#include <misaxx-ome-visualizer/module_info.h>
#include <misaxx/core/runtime/misa_cli.h>

using namespace misaxx;
using namespace misaxx_ome_visualizer;

int main(int argc, const char** argv) {
    misa_cli cli {};
    cli.set_module_info(misaxx_ome_visualizer::module_info());
    cli.set_root_module<misaxx_ome_visualizer::module>("misaxx-ome-visualizer");
    return cli.prepare_and_run(argc, argv);
}