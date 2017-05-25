from distutils.core import setup, Extension

module1 = Extension('pylyra',
                    sources=['lyramodule.c',
                             'Lyra/Lyra2/src/Lyra2.c',
                             'Lyra/Lyra2/src/Sponge.c'],
                    depends=['Lyra/Lyra2/src/*.h'],
                    extra_compile_args=['-fopenmp'],
                    extra_link_args=['-fopenmp'])


setup(name='PackageName',
      version='1.0',
      description='This is a demo package',
      ext_modules=[module1])
