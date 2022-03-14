cmake_minimum_required(VERSION 3.17)
project(ProiectFinalOOP)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProiectFinalOOP main.cpp Domain/OperaDeArta.cpp Domain/OperaDeArta.h Utils.cpp Utils.h Tests/tests.cpp Tests/tests.h Domain/Sculptura.cpp Domain/Sculptura.h Domain/Tablou.cpp Domain/Tablou.h Tests/TestRepo.cpp Tests/TestRepo.h Repository/Repo.cpp Repository/Repo.h Validator/Validator.cpp Validator/Validator.h Validator/ValidationException.h Validator/ValidatorSculptura.cpp Validator/ValidatorSculptura.h Validator/ValidatorTablou.cpp Validator/ValidatorTablou.h Exceptions/RepoException.h Service/Service.cpp Service/Service.h UI/UI.cpp UI/UI.h Repository/RepoFile.cpp Repository/RepoFile.h Exceptions/ReadFromFileException.h)