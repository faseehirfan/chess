CXX = g++
CXXFLAGS = -std=c++14 -g -Wall
EXEC = chess

SRCS = main.cc controller.cc human.cc board.cc view.cc textView.cc piece.cc square.cc rook.cc pawn.cc types.cc knight.cc queen.cc bishop.cc king.cc computer.cc levelone.cc leveltwo.cc levelthree.cc levelfour.cc graphicsView.cc window.cc
HEADERS = controller.h types.h player.h human.h board.h make.h view.h textView.h square.h piece.h rook.h pawn.h knight.h queen.h bishop.h king.h computer.h levelone.h leveltwo.h levelthree.h levelfour.h graphicsView.h window.h
OBJS = $(SRCS:.cc=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS) -lX11

%.o: %.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
