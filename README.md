# string
[ 33%] Building CXX object CMakeFiles/cpp-24-25-string.dir/cpp-24-25-string.cpp.o
/builds/cpp_course_2425/cpp_course2425_aleksandr-iosipoi_2024/cpp-24-25-string/cpp-24-25-string.cpp:235:24: error: member reference base type 'char *const' is not a structure or union
  235 |    while ((end = data1_.find(delim.data1_, start)) != std::string::npos) {
      |                  ~~~~~~^~~~~
/builds/cpp_course_2425/cpp_course2425_aleksandr-iosipoi_2024/cpp-24-25-string/cpp-24-25-string.cpp:236:38: error: member reference base type 'char *const' is not a structure or union
  236 |        result.push_back(String(data1_.substr(start, end - start).c_str()));
      |                                ~~~~~~^~~~~~~
/builds/cpp_course_2425/cpp_course2425_aleksandr-iosipoi_2024/cpp-24-25-string/cpp-24-25-string.cpp:239:34: error: member reference base type 'char *const' is not a structure or union
  239 |    result.push_back(String(data1_.substr(start).c_str())); // Последняя часть после последнего делиметра
      |                            ~~~~~~^~~~~~~
3 errors generated.
