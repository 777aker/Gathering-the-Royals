project('DBB', 'cpp', default_options: ['cpp_std=c++20'])

deps = [dependency('glfw3'), dependency('glut'), dependency('threads')]

dbbe_include = 'dbbe/'
dbbe_sources = ['dbbe/loadtexbmp.cpp', 'dbbe/shader.cpp', 'dbbe/window.cpp']
dbbe_lib = shared_library('dbbe', dbbe_sources, include_directories: dbbe_include, dependencies: deps, link_with: [], link_args: ['-lglfw', '-lGLU', '-lGL', '-lm'])

inc = include_directories('.')
program_sources = ['main.cpp']
exec = executable('dbb', program_sources, include_directories: inc, dependencies: deps, link_with: [dbbe_lib], link_args: ['-lglfw', '-lGLU', '-lGL', '-lm'])
