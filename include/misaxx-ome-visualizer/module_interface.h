#include <misaxx/core/misa_module_interface.h>
#include <misaxx/ome/accessors/misa_ome_tiff.h>

namespace misaxx_ome_visualizer {
    struct module_interface : public misaxx::misa_module_interface {

        misaxx::ome::misa_ome_tiff m_input;
        misaxx::ome::misa_ome_tiff m_output;

        void setup() override;
    };
}
