src/Bcat.cpp: In member function ‘bool Bcat::read()’:
src/Bcat.cpp:41:36: error: no matching function for call to ‘getline(std::istream&, std::__cxx11::wstring&)’
       while (getline(std::cin, line))
                                    ^
In file included from /usr/include/c++/6/cstdio:42:0,
                 from /usr/include/c++/6/ext/string_conversions.h:43,
                 from /usr/include/c++/6/bits/basic_string.h:5417,
                 from /usr/include/c++/6/string:52,
                 from ./include/Bcat.hh:5,
                 from src/Bcat.cpp:1:
/usr/include/stdio.h:680:20: note: candidate: __ssize_t getline(char**, size_t*, FILE*)
 extern _IO_ssize_t getline (char **__restrict __lineptr,
                    ^~~~~~~
/usr/include/stdio.h:680:20: note:   candidate expects 3 arguments, 2 provided
In file included from /usr/include/c++/6/string:52:0,
                 from ./include/Bcat.hh:5,
                 from src/Bcat.cpp:1:
/usr/include/c++/6/bits/basic_string.h:5395:5: note: candidate: template<class _CharT, class _Traits, class _Alloc> std::basic_istream<_CharT, _Traits>& std::getline(std::basic_istream<_CharT, _Traits>&&, std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&)
     getline(basic_istream<_CharT, _Traits>&& __is,
     ^~~~~~~
/usr/include/c++/6/bits/basic_string.h:5395:5: note:   template argument deduction/substitution failed:
src/Bcat.cpp:41:36: note:   deduced conflicting types for parameter ‘_CharT’ (‘char’ and ‘wchar_t’)
       while (getline(std::cin, line))
                                    ^
In file included from /usr/include/c++/6/string:52:0,
                 from ./include/Bcat.hh:5,
                 from src/Bcat.cpp:1:
/usr/include/c++/6/bits/basic_string.h:5388:5: note: candidate: template<class _CharT, class _Traits, class _Alloc> std::basic_istream<_CharT, _Traits>& std::getline(std::basic_istream<_CharT, _Traits>&&, std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&, _CharT)
     getline(basic_istream<_CharT, _Traits>&& __is,
     ^~~~~~~
/usr/include/c++/6/bits/basic_string.h:5388:5: note:   template argument deduction/substitution failed:
src/Bcat.cpp:41:36: note:   deduced conflicting types for parameter ‘_CharT’ (‘char’ and ‘wchar_t’)
       while (getline(std::cin, line))
                                    ^
In file included from /usr/include/c++/6/string:52:0,
                 from ./include/Bcat.hh:5,
                 from src/Bcat.cpp:1:
/usr/include/c++/6/bits/basic_string.h:5380:5: note: candidate: template<class _CharT, class _Traits, class _Alloc> std::basic_istream<_CharT, _Traits>& std::getline(std::basic_istream<_CharT, _Traits>&, std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&)
     getline(basic_istream<_CharT, _Traits>& __is,
     ^~~~~~~
/usr/include/c++/6/bits/basic_string.h:5380:5: note:   template argument deduction/substitution failed:
src/Bcat.cpp:41:36: note:   deduced conflicting types for parameter ‘_CharT’ (‘char’ and ‘wchar_t’)
       while (getline(std::cin, line))
                                    ^
In file included from /usr/include/c++/6/string:53:0,
                 from ./include/Bcat.hh:5,
                 from src/Bcat.cpp:1:
/usr/include/c++/6/bits/basic_string.tcc:1509:5: note: candidate: template<class _CharT, class _Traits, class _Alloc> std::basic_istream<_CharT, _Traits>& std::getline(std::basic_istream<_CharT, _Traits>&, std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&, _CharT)
     getline(basic_istream<_CharT, _Traits>& __in,
     ^~~~~~~
/usr/include/c++/6/bits/basic_string.tcc:1509:5: note:   template argument deduction/substitution failed:
src/Bcat.cpp:41:36: note:   deduced conflicting types for parameter ‘_CharT’ (‘char’ and ‘wchar_t’)
       while (getline(std::cin, line))
                                    ^
make: *** [src/Bcat.o] Erreur 1
