add_library(data_structures
        vector/vector.h
        vector/vector.c
        matrix/matrix.h
        matrix/matrix.c)

target_link_libraries(data_structures algorithms)
