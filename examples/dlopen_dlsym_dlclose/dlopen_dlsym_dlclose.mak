# ****************************************************************************
# *                                                                          *
# *  dlopen_dlsym_dlclose.mak                                                                 *
# *  =======                                                                 *
# *                                                                          *
# ****************************************************************************

# ****************************************************************************
# *                                                                          *
# *  Define the name of the makefile.                                        *
# *                                                                          *
# ****************************************************************************

MAKNAM = dlopen_dlsym_dlclose.mak

# ****************************************************************************
# *                                                                          *
# *  Define the directories in which to search for library files.            *
# *                                                                          *
# ****************************************************************************

LIBDRS =

# ****************************************************************************
# *                                                                          *
# *  Define the directories in which to search for include files.            *
# *                                                                          *
# ****************************************************************************

INCDRS = -I$(ALGOWC_TOPDIR)/include

# ****************************************************************************
# *                                                                          *
# *  Define the library files.                                               *
# *                                                                          *
# ****************************************************************************

LIBFLS =

# ****************************************************************************
# *                                                                          *
# *  Define the source files.                                                *
# *                                                                          *
# ****************************************************************************

SRCFLS = dlopen_dlsym_dlclose.c

# ****************************************************************************
# *                                                                          *
# *  Define the object files.                                                *
# *                                                                          *
# ****************************************************************************

OBJFLS = dlopen_dlsym_dlclose.o

# ****************************************************************************
# *                                                                          *
# *  Define the executable.                                                  *
# *                                                                          *
# ****************************************************************************

EXE    = dlopen_dlsym_dlclose.exe

# ****************************************************************************
# *                                                                          *
# *  Define the compile and link options.                                    *
# *                                                                          *
# ****************************************************************************

CC     = gcc
LL     = gcc
CFLAGS =
LFLAGS = -ldl

# ****************************************************************************
# *                                                                          *
# *  Define the rules.                                                       *
# *                                                                          *
# ****************************************************************************

$(EXE): $(OBJFLS)
	$(LL)  -o $@ $(OBJFLS) $(LIBDRS) $(LIBFLS) $(LFLAGS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $(INCDRS) $<

all:
	make -f $(MAKNAM) clean
	make -f $(MAKNAM) depend

depend:
	makedepend $(INCDRS) -f $(MAKNAM) $(SRCFLS)
	make -f $(MAKNAM) $(EXE)

clean:
	-rm $(EXE)
	-rm $(OBJFLS)

# DO NOT DELETE THIS LINE -- make depend depends on it.
