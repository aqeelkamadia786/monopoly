# More complex makefile
CXX = g++          # define compiler to use for C++ programs
CXXFLAGS = -Wall   # define flags to use
#CXXFLAGS = -g -DDEBUG -Wall  # define alternate flags to use

# Define some variables to reduce duplication and possible errors.
#
SRCS = dice.cc square.cc building.cc slc.cc coopfee.cc tuition.cc goosenesting.cc needleshall.cc gym.cc gototims.cc dctimsline.cc residence.cc academicbuilding.cc game.cc collectosap.cc player.cc main.cc
OBJS = $(SRCS:.cc=.o)   # Define that we want to turn *.cc from SRCS into *.o
EXEC = bb7k

# Define first/default rule
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ # Use $@ to get target name

# Define other, non-obvious dependencies i.e. x.o implicitly depends on x.{h,cc}
# so don't need to specify that.


# Define a generic rule for turning file x.cc into x.o.
.cc.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

# Define rule to clean up.
clean:
	rm *.o $(EXEC)
