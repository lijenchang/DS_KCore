CC = g++ -O3 -lm -std=c++11

#SRCS = ../*.cpp
RO_SRCS = ./*.cpp

find_coreness:
	$(CC) -o $@ $(RO_SRCS)


#RO: $(RO_SRCS)
#	$(CC) -c $(RO_SRCS)

.PHONY: clean

clean:
ifeq ($(OS),Windows_NT)
	del find_coreness.exe *.o
else
	rm find_coreness *.o
endif
