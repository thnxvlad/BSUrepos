cmake_minimum_required(VERSION 3.17)
project(Vocabulary)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)
include_directories(Debug)
include_directories(Vocabulary)

add_executable(Vocabulary
        .idea/workspace.xml
        Debug/Vocabulary.exe
        Debug/Vocabulary.ilk
        Debug/Vocabulary.pdb
        Vocabulary/Debug/Vocabulary.tlog/CL.command.1.tlog
        Vocabulary/Debug/Vocabulary.tlog/CL.read.1.tlog
        Vocabulary/Debug/Vocabulary.tlog/CL.write.1.tlog
        Vocabulary/Debug/Vocabulary.tlog/link.command.1.tlog
        Vocabulary/Debug/Vocabulary.tlog/link.read.1.tlog
        Vocabulary/Debug/Vocabulary.tlog/link.write.1.tlog
        Vocabulary/Debug/Vocabulary.tlog/unsuccessfulbuild
        Vocabulary/Debug/Vocabulary.tlog/Vocabulary.lastbuildstate
        Vocabulary/Debug/BiDirectionalListOnArray.obj
        Vocabulary/Debug/FileReader.obj
        Vocabulary/Debug/main.obj
        Vocabulary/Debug/vc142.idb
        Vocabulary/Debug/vc142.pdb
        Vocabulary/Debug/Vocabulary.Build.CppClean.log
        Vocabulary/Debug/Vocabulary.exe.recipe
        Vocabulary/Debug/Vocabulary.log
        Vocabulary/Debug/Vocabulary.obj
        Vocabulary/Debug/Vocabulary.vcxproj.FileListAbsolute.txt
        Vocabulary/BiDirectionalListOnArray.cpp
        Vocabulary/BiDirectionalListOnArray.h
        Vocabulary/containers.h
        Vocabulary/FileReader.cpp
        Vocabulary/FileReader.h
        Vocabulary/kr2_gr3_eryomenko_vlad.zip
        Vocabulary/main.cpp
        Vocabulary/Vocabulary.cpp
        Vocabulary/Vocabulary.h
        Vocabulary/Vocabulary.vcxproj
        Vocabulary/Vocabulary.vcxproj.filters
        Vocabulary/Vocabulary.vcxproj.user
        Vocabulary/WordCard.cpp
        Vocabulary/WordCard.h
        Vocabulary.sln)
