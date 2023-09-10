"""
See LICENSE file for copyright and license details.

Given the root to a binary tree, implement serialize(root), which
serializes the tree into a string, and deserialize(s), which
deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
"""
from collections import deque


class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def bar(queue):
    val = queue.popleft()
    if val == '\t':
        return None
    else:
        node = Node(val)
        node.left = bar(queue)
        node.right = bar(queue)
        return node


def deserialize(s):
    l = s.split('/')
    return bar(deque(l))


def foo(node, queue):
    if node is None:        
        queue.append('\t')
    else:
        queue.append(node.val)
        foo(node.left, queue)
        foo(node.right, queue)


def serialize(root):
    queue = deque([])
    foo(root, queue)
    return '/'.join(queue)


if __name__=='__main__':
    node = Node('root', Node('left', Node('left.left')), Node('right'))
    assert deserialize(serialize(node)).left.left.val == 'left.left'
