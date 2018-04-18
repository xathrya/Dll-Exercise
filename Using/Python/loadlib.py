import ctypes

lib = ctypes.WinDLL('hello.dll')
world = lib['world']
world()