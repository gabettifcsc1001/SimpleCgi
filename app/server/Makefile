COMPILER  = g++
CFLAGS    = -g -MMD -MP -Wall -Wextra -Winit-self -Wno-missing-field-initializers
# CFLAGS    = -g -MMD -MP
ifeq "$(shell getconf LONG_BIT)" "64"
  LDFLAGS = -L/Library/PostgreSQL/9.5/lib -L /usr/local/lib -lpq
else
  LDFLAGS = -L/Library/PostgreSQL/9.5/lib -L /usr/local/lib -lpq
endif
LIBS      =
INCLUDE   = -I ./include -I /Library/PostgreSQL/9.5/include/postgresql -I /Library/PostgreSQL/9.5/include/postgresql/server -I /usr/local/Cellar/postgresql/9.5.1/include/server
CGINAME   = SimpleCgi
TARGETDIR = ./bin
TARGET    =$(addprefix $(TARGETDIR)/, $(CGINAME))
SRCDIR    = ./src
ifeq "$(strip $(SRCDIR))" ""
  SRCDIR  = .
endif
SOURCES   = $(wildcard $(SRCDIR)/*.cpp)
OBJDIR    = ./obj
ifeq "$(strip $(OBJDIR))" ""
  OBJDIR  = .
endif
OBJECTS   = $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.cpp=.o)))
DEPENDS   = $(OBJECTS:.o=.d)

$(TARGET): $(OBJECTS) $(LIBS)
	$(COMPILER) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	-mkdir -p $(OBJDIR)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all: clean $(TARGET)

clean:
	-rm -f $(OBJECTS) $(DEPENDS) $(TARGET)

-include $(DEPENDS)
