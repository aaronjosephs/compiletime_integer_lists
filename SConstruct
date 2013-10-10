progs = Split( '''
        generate
        generate_with_function
        ''')

cxx = 'c++'
cxx_flags = ' -Wall -Wextra -pedantic -std=c++11 -I/usr/local/include'
ldflags = ' -L/usr/local/lib'
#for mac
depth = raw_input("Enter max template depth, default is 124: ")
ldflags += ' -stdlib=libc++ ' + ('-ftemplate-depth=' + depth) if depth else ''
cxx_flags += ' -stdlib=libc++ ' + ('-ftemplate-depth=' + depth) if depth else ''
for p in progs:
    Program(source='test{0}.cpp'.format(p),
            CXXFLAGS=cxx_flags, CPPPATH='..', CXX=cxx,
            LINKFLAGS=ldflags)
