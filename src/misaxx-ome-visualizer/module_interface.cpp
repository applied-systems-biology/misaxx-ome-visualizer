#include <misaxx-ome-visualizer/module_info.h>
#include <misaxx-ome-visualizer/module_interface.h>


using namespace misaxx;
using namespace misaxx_ome_visualizer;

void misaxx_ome_visualizer::module_interface::setup() {
    m_input.suggest_import_location(filesystem, "/");
    m_output.suggest_export_location(filesystem, "/", m_input.derive().of_opencv(CV_8UC3));
}
