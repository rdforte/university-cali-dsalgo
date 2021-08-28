  long long multipleA = a;
  long long multipleB = b;

  while (multipleB % a != 0 || multipleA % b != 0)
  {
    if (multipleB % a != 0)
      multipleB += b;
    if (multipleA % b != 0)
      multipleA += a;
  }

  return multipleA;