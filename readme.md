SPAeCE algorithm control class. Provides time-loop and SPAeCE-loop control methods.
	
**Make/files**

	general = cfdTools/general
	solutionControl = $(general)/solutionControl
	$(solutionControl)/spvppcControl/spvppcControl.C
     
	LIB = $(FOAM_USER_LIBBIN)/libfiniteVolume_$(USER)

**Make/options**

	EXE_INC = \
	    -I$(LIB_SRC)/triSurface/lnInclude \
	    -I$(LIB_SRC)/meshTools/lnInclude \
	    -I$(LIB_SRC)/finiteVolume/lnInclude \
     
	LIB_LIBS = \
	    -ltriSurface \
	    -lmeshTools \
	    -lfiniteVolume \
	    -L$(FOAM_USER_LIBBIN)