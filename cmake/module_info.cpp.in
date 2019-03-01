#include <misaxx/core/misa_mutable_module_info.h>
#include <misaxx/core/module_info.h>
#include <misaxx-ome-visualizer/module_info.h>
#include <misaxx/ome/module_info.h>

misaxx::misa_module_info misaxx_ome_visualizer::module_info() {
    misaxx::misa_mutable_module_info info;
    info.set_id("@PROJECT_NAME@");
    info.set_version("@PROJECT_VERSION@");
    info.set_name("@PROJECT_DESCRIPTION@");
    info.set_description("Visualized OME TIFF images");
    info.add_author("Ruman Gerst");
    info.set_license("BSD-2-Clause");
    info.set_organization("Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Institute (HKI), Jena, Germany");
    info.set_url("https://asb-git.hki-jena.de/RGerst/misaxx-ome-visualizer/");

    info.add_dependency(misaxx::module_info());
    info.add_dependency(misaxx::ome::module_info());

    return info;
}