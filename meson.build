project('xhk', 'c',
  version : '1.0.0',
  #c_std : 'c99'
)

project_source_files = [
  'src/daemon.c',
  'src/xhk.c'
]

project_dependencies = [
  dependency('xcb'),
  dependency('X11')
]

project_include_directories = [
  include_directories('include')
]

build_args = [
]

# =============================
# TARGET
# =============================

build_args += [
  '-DVERSION="' + meson.project_version() + '"',
  '-Wall', 
  '-pedantic',
  '-Wunused-parameter',
	'-Wimplicit-function-declaration',
  '-Wunreachable-code',
  '-Wunused-macros',
  '-pipe',
  '-march=native'
]

project_target = executable(
    meson.project_name(),
    project_source_files,
    install : true,
    include_directories : project_include_directories,
    dependencies : project_dependencies,
    c_args : build_args
)
