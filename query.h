// LICENSE
// This software is free for use and redistribution while including this
// license notice, unless:
// 1. is used for commercial or non-personal purposes, or
// 2. used for a product which includes or associated with a blockchain or other
// decentralized database technology, or
// 3. used for a product which includes or associated with the issuance or use
// of cryptographic or electronic currencies/coins/tokens.
// On all of the mentioned cases, an explicit and written permission is required
// from the Author (Ohad Asor).
// Contact ohad@idni.org for requesting a permission. This license may be
// modified over time by the Author.
#include "bdd.h"

class query {
	const bool neg;
	const size_t bits, nvars;
	const ints e;
	const sizes perm, domain;
	std::vector<char> path;
	sizes getdom() const;
	std::unordered_map<size_t, size_t> memo;
	size_t compute(size_t x, size_t v);
public:
	query(size_t bits, const term& t, const sizes& perm);
	size_t operator()(size_t x);
};

class bdd_and_eq {
	const size_t bits, nvars;
	const ints e;
	const sizes domain;
	std::vector<char> path;
	sizes getdom() const;
	std::unordered_map<size_t, size_t> memo;
	size_t compute(size_t x, size_t v);
public:
	bdd_and_eq(size_t bits, const term& t);
	size_t operator()(size_t x);
};
/*
class extents {
	const size_t bits, nvars, tail;
	const int_t glt, ggt;
	const term excl, lt, gt;
	const sizes succ, pred, domain;
	bools path;
	sizes getdom() const;
	int_t get_int(size_t pos) const;
	std::unordered_map<size_t, size_t> memo;
	size_t compute(size_t x, size_t v);
public:
	extents(size_t bits, size_t ar, size_t tail, const sizes& domain,
		int_t glt, int_t ggt, const term& excl, const term& lt,
		const term& gt, const sizes& succ, const sizes& pred);
	size_t operator()(size_t x);
};*/