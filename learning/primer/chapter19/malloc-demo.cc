#include <cstdlib>
#include <new>

using namespace std;

void* operator new(size_t sz) {
	if (void* mem = malloc(sz)) {
		return mem;
	}
	else {
		throw bad_alloc();
	}
}

void operator delete(void* mem) noexcept {
	free(mem);
}