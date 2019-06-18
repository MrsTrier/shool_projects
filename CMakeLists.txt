aux_source_directory(./src/list list_src)
aux_source_directory(./src/string string_src)
aux_source_directory(./src/printf printf_src)


include_directories(include)
add_library(libft_lib ${list_src} ${string_src} ${printf_src})