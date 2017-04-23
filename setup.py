from distutils.core import setup, Extension

module1 = Extension('pylyra',
                    sources=['lyramodule.c', 'Lyra.c', 'Sponge.c'],
                    depends=['*.h'])

setup (name = 'PackageName',
       version = '1.0',
       description = 'This is a demo package',
       ext_modules = [module1])
