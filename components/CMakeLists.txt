# Register the component
idf_component_register(...)

set(FOO_BUILD_TESTS OFF)

add_prebuilt_library(print ${ASMSHARP_COMPONENTS}/libprint.a)

target_link_libraries(${COMPONENT_LIB} INTERFACE print)
