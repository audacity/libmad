cmake_minimum_required( VERSION 3.15 )

project( libmad )

include(CMakeDependentOption)

set( TARGET libmad )

cmake_dependent_option( BUILD_SHARED "Build a shared library" Off "NOT WIN32" Off)
option( OPT_ACCURACY "Favour accuracy" On)
option( OPT_SPEED "Favour speed" Off)
option( OPT_SSO "Enable a fast subband synthesis approximation optimization" Off)

if( BUILD_SHARED )
   add_library( ${TARGET} SHARED )
else()
   add_library( ${TARGET} STATIC )
endif()

set(EXPORTED_HEADERS
   detect_fpm.h 
   version.h 
   fixed.h 
   bit.h 
   timer.h 
   stream.h 
   frame.h		
   synth.h 
   decoder.h
)

target_sources( ${TARGET} 
   PRIVATE 
     bit.c
     decoder.c
     fixed.c
     frame.c
     huffman.c
     layer12.c
     layer3.c
     stream.c
     synth.c
     timer.c
     version.c
)

target_include_directories( ${TARGET} PRIVATE . "${CMAKE_BINARY_DIR}/include" )

target_compile_definitions( ${TARGET} 
   PRIVATE
      HAVE_CONFIG_H
      OPT_ACCURACY
      ${FPM}
)

target_compile_options( ${TARGET} 
   PRIVATE
      $<$<C_COMPILER_ID:AppleClang,Clang,GNU>:-Wall>
      $<$<C_COMPILER_ID:AppleClang,Clang,GNU>:-fPIC>
)

set (MAD_H "${CMAKE_BINARY_DIR}/include/mad.h")

configure_file( config.h.in "${CMAKE_BINARY_DIR}/include/config.h" )
configure_file( mad.h.in "${MAD_H}" )

foreach( header ${EXPORTED_HEADERS} )
   file( READ ${header} HEADER_DATA )
   file( APPEND ${MAD_H} "// #include \"${header}\"\n\n${HEADER_DATA}\n" )
endforeach()

file( APPEND ${MAD_H} "#endif\n" )


install(TARGETS ${TARGET})
install(FILES ${MAD_H} DESTINATION TYPE INCLUDE)
