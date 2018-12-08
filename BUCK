load('//:subdir_glob.bzl', 'subdir_glob')
load('//:buckaroo_macros.bzl', 'buckaroo_deps')

cxx_library(
  name = 'oatpp-curl', 
  header_namespace = '', 
  exported_headers = subdir_glob([
    ('', '*.hpp'), 
    ('', 'io/**/*.hpp'), 
  ]), 
  srcs = glob([
    '*.cpp', 
    'io/**/*.cpp', 
  ]), 
  licenses = [
    'LICENSE', 
  ], 
  deps = buckaroo_deps(), 
  visibility = [
    'PUBLIC', 
  ], 
)
