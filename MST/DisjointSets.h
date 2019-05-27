#pragma once

class DisjointSets
{
public:
	DisjointSets(int n);
	~DisjointSets();
	int find(int u);
	void merge(int x, int y);


	int* parent, * rnk;
	int n;
};
