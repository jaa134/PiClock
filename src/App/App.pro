TEMPLATE = subdirs  
SUBDIRS += PiClock \ 
    PiClockUnitTests \
    PiClockLib \
    PiClockGUITests/PiClockGUITests

PiClock.depends = PiClockLib
PiClockUnitTests.depends = PiClockLib
