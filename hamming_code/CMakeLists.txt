# CMakeList.txt: projeto de CMake para hamming_code, incluir origem e definir
# lógica específica a um projeto aqui.
#
cmake_minimum_required (VERSION 3.8)

project ("hamming_code")

# Adicione a origem ao executável deste projeto.
add_executable (hamming_code  "hamming_code.h" "hamming_code.c")

# TODO: Adicione testes e instale destinos, se necessário.
