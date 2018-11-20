TEMPLATE = subdirs  
SUBDIRS += PiClock \ 
    PiClockUnitTests \
    PiClockLib

# --coverage option is synonym for: -fprofile-arcs -ftest-coverage -lgcov
LIBS += -lgcov
QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage

PiClock.depends = PiClockLib
PiClockUnitTests.depends = PiClockLib
