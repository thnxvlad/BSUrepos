# CMakeList.txt: проект CMake для bi_directional_list_on_array; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (bi_directional_list_on_array   "bidirectional_list_on_array.cpp" "bidirectional_list_on_array.h" "containers.h" "file_reader.cpp" "file_reader.h" "main.cpp" "vocabulary.cpp" "vocabulary.h" "word_card.cpp" "word_card.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
