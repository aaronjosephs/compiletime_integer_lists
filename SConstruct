progs = Split( '''
        generate
        ''')

cxx = 'c++'
cxx_flags = ' -Wall -Wextra -pedantic -std=c++11 -I/usr/local/include'
ldflags = ' -L/usr/local/lib'
#for mac
ldflags += ' -stdlib=libc++ -ftemplate-depth=900'
cxx_flags += ' -stdlib=libc++ -ftemplate-depth=900'

for p in progs:
    Program(source='test{0}.cpp'.format(p),
            CXXFLAGS=cxx_flags, CPPPATH='..', CXX=cxx,
            LINKFLAGS=ldflags)
