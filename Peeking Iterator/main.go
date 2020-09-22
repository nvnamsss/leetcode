package main

type Iterator struct {
}

type PeekingIterator struct {
	val    int
	peeked bool
	iter   *Iterator
}

// func (this *Iterator) hasNext() bool {
// 	// Returns true if the iteration has more elements.
// }

// func (this *Iterator) next() int {
// 	// Returns the next element in the iteration.
// }

func Constructor(iter *Iterator) *PeekingIterator {
	p := new(PeekingIterator)
	p.iter = iter
	p.peeked = false

	return p
}

func (this *PeekingIterator) hasNext() bool {
	if this.peeked {
		return true
	}

	return this.iter.hasNext()
}

func (this *PeekingIterator) next() int {
	if !this.peeked {
		return this.iter.next()
	}

	this.peeked = false
	return this.val
}

func (this *PeekingIterator) peek() int {
	if !this.peeked {
		this.val = this.iter.next()
		this.peeked = true
	}

	return this.val
}
