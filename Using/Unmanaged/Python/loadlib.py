# Load library on runtime
# Use ctypes to load the library and then get the function address
#
# Run:
#   $ python loadlib.py

import ctypes

# Load the DLL module to executable mapped memory
# Before getting the address of funciton, we need to load the library
# and let it mapped to our memory
lib = ctypes.WinDLL('unmanaged.dll')

# Get the function by name
world = lib['world']
calculate = lib['calculate']

# Call the function
world()
print("The result of calculation(0) is {}".format(calculate(0)))