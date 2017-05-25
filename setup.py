from setuptools import setup, Extension

pylyra_module = Extension('pylyra',
                          sources=['lyramodule.c',
                                   'Lyra/Lyra2/src/Lyra2.c',
                                   'Lyra/Lyra2/src/Sponge.c'],
                          depends=['Lyra/Lyra2/src/*.h'],
                          extra_compile_args=['-fopenmp'],
                          extra_link_args=['-fopenmp'])


setup(name='pylyra',
      version='1.0',
      description='Python implementation of Lyra2',
      ext_modules=[pylyra_module],
      url="https://github.com/leocalm/pylyra",
      # Author details
      author='Leonardo C. Almeida',
      author_email='leocalm@gmail.com',
      # Choose your license
      license='MIT',
      classifiers=[
        'Development Status :: 4 - Beta',

        # Indicate who your project is intended for
        'Intended Audience :: Developers',
        'Topic :: Security :: Cryptography',

        # Pick your license as you wish (should match "license" above)
        'License :: OSI Approved :: MIT License',

        # Specify the Python versions you support here. In particular, ensure
        # that you indicate whether you support Python 2, Python 3 or both.
        'Programming Language :: Python :: 2',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.3',
        'Programming Language :: Python :: 3.4',
        'Programming Language :: Python :: 3.5',
        'Programming Language :: Python :: 3.6',
      ],
      keywords='security password development')
