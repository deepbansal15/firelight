# Define FLT_DEFAULT_LINKOPTS for common libraries
function(flt_add_library)
  cmake_parse_arguments(FLT_CC_LIB
    "STATIC","SHARED","OBJECT"
    "NAME"
    "HDRS;SRCS;COPTS;DEFINES;LINKOPTS;DEPS"
    ${ARGN}
  )

  set(FLT_NAME "flt_${FLT_CC_LIB_NAME}")

  if(FLT_CC_LIB_OBJECT)
    add_library(${FLT_NAME} OBJECT "")
  elseif(FLT_CC_LIB_SHARED)
    add_library(${FLT_NAME} SHARED "")
  else()
    add_library(${FLT_NAME} STATIC "")
  endif()

  target_sources(${FLT_NAME} PRIVATE ${FLT_CC_LIB_SRCS} ${FLT_CC_LIB_HDRS})
  target_link_libraries(${FLT_NAME} 
    PRIVATE 
      ${FLT_CC_LIB_DEPS}
      ${FLT_CC_LIB_LINKOPTS}
      ${FLT_DEFAULT_LINKOPTS}
  )

  target_include_directories(${FLT_NAME}
    PUBLIC "$<BUILD_INTERFACE:${FLT_CC_LIB_HDRS}"
  )

  target_compile_options(${FLT_NAME}
    PRIVATE ${FLT_CC_LIB_COPTS}
  )
  target_compile_definitions(${FLT_NAME} PUBLIC ${FLT_CC_LIB_DEFINES})

endfunction()

function(flt_add_test)
endfunction()

function(flt_add_benchmark)
endfunction()