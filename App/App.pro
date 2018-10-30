TEMPLATE = subdirs  
SUBDIRS += PiClock \ 
    PiClockUnitTests \
    PiClockLib

PiClock.depends = PiClockLib
PiClockUnitTests.depends = PiClockLib
