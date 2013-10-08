progs = Split( '''
        array_generator
        ''')

cxx = 'c++'
cxx_flags = ' -Wall -Wextra -pedantic -std=c++11 -I/usr/local/include'
ldflags = ' -L/usr/local/lib'
#for mac
ldflags += ' -stdlib=libc++ '
cxx_flags += ' -stdlib=libc++ '

for p in progs:
    Program(source='{0}.cpp'.format(p),
            CXXFLAGS=cxx_flags, CPPPATH='..', CXX=cxx,
            LINKFLAGS=ldflags)
