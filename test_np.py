#! /usr/bin/env python
import qf

test = qf.test_wrap()
print("values has type %s" % test.values.__class__)
print("values has len %d" % len(test.values))
print("values is %s" % str(test.values))
