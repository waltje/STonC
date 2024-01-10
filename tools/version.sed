# get the version from the changelog

/^[0-9]/{
  s/.*/#define VERSION "&"/
  q
}
/^Version */{
  s///
  s/.*/#define VERSION "&"/
  q
}
d

