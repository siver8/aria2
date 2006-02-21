#include "Util.h"
#include <string>
#include <cppunit/extensions/HelperMacros.h>

using namespace std;

class UtilTest:public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(UtilTest);
  CPPUNIT_TEST(testTrim);
  CPPUNIT_TEST(testSplit);
  CPPUNIT_TEST(testSlice);
  CPPUNIT_TEST(testEndsWith);
  CPPUNIT_TEST(testReplace);
  CPPUNIT_TEST_SUITE_END();
private:

public:
  void setUp() {
  }

  void testTrim();
  void testSplit();
  void testSlice();
  void testEndsWith();
  void testReplace();
};


CPPUNIT_TEST_SUITE_REGISTRATION( UtilTest );

void UtilTest::testTrim() {
  string str1 = "aria2";
  CPPUNIT_ASSERT_EQUAL(str1, Util::trim("aria2"));
  CPPUNIT_ASSERT_EQUAL(str1, Util::trim(" aria2"));
  CPPUNIT_ASSERT_EQUAL(str1, Util::trim(" aria2 "));
  CPPUNIT_ASSERT_EQUAL(str1, Util::trim("  aria2  "));
  string str2 = "aria2 debut";
  CPPUNIT_ASSERT_EQUAL(str2, Util::trim("aria2 debut"));
  CPPUNIT_ASSERT_EQUAL(str2, Util::trim(" aria2 debut "));
  string str3 = "";
  CPPUNIT_ASSERT_EQUAL(str3, Util::trim(""));
  CPPUNIT_ASSERT_EQUAL(str3, Util::trim(" "));
  CPPUNIT_ASSERT_EQUAL(str3, Util::trim("  "));
  string str4 = "A";
  CPPUNIT_ASSERT_EQUAL(str4, Util::trim("A"));
  CPPUNIT_ASSERT_EQUAL(str4, Util::trim(" A "));
  CPPUNIT_ASSERT_EQUAL(str4, Util::trim("  A  "));
}

void UtilTest::testSplit() {
  pair<string, string> p1;
  Util::split(p1, "name=value", '=');
  CPPUNIT_ASSERT_EQUAL(string("name"), p1.first);
  CPPUNIT_ASSERT_EQUAL(string("value"), p1.second);
  Util::split(p1, " name = value ", '=');
  CPPUNIT_ASSERT_EQUAL(string("name"), p1.first);
  CPPUNIT_ASSERT_EQUAL(string("value"), p1.second);
  Util::split(p1, "=value", '=');
  CPPUNIT_ASSERT_EQUAL(string(""), p1.first);
  CPPUNIT_ASSERT_EQUAL(string("value"), p1.second);
  Util::split(p1, "name=", '=');
  CPPUNIT_ASSERT_EQUAL(string("name"), p1.first);
  CPPUNIT_ASSERT_EQUAL(string(""), p1.second);
  Util::split(p1, "name", '=');
  CPPUNIT_ASSERT_EQUAL(string("name"), p1.first);
  CPPUNIT_ASSERT_EQUAL(string(""), p1.second);
}

void UtilTest::testSlice() {
  vector<string> v1;
  Util::slice(v1, "name1=value1; name2=value2; name3=value3;", ';');
  CPPUNIT_ASSERT_EQUAL(3, (int)v1.size());
  v1.clear();
  Util::slice(v1, "name1=value1; name2=value2; name3=value3", ';');
  CPPUNIT_ASSERT_EQUAL(3, (int)v1.size());
  vector<string>::iterator itr = v1.begin();
  CPPUNIT_ASSERT_EQUAL(string("name1=value1"), *itr++);
  CPPUNIT_ASSERT_EQUAL(string("name2=value2"), *itr++);
  CPPUNIT_ASSERT_EQUAL(string("name3=value3"), *itr++);
}

void UtilTest::testEndsWith() {
  string target = "abcdefg";
  string part = "fg";
  CPPUNIT_ASSERT(Util::endsWith(target, part));

  target = "abdefg";
  part = "g";
  CPPUNIT_ASSERT(Util::endsWith(target, part));

  target = "abdefg";
  part = "eg";
  CPPUNIT_ASSERT(!Util::endsWith(target, part));

  target = "g";
  part = "eg";
  CPPUNIT_ASSERT(!Util::endsWith(target, part));

  target = "g";
  part = "g";
  CPPUNIT_ASSERT(Util::endsWith(target, part));

  target = "g";
  part = "";
  CPPUNIT_ASSERT(Util::endsWith(target, part));

  target = "";
  part = "";
  CPPUNIT_ASSERT(Util::endsWith(target, part));

  target = "";
  part = "g";
  CPPUNIT_ASSERT(!Util::endsWith(target, part));
}

void UtilTest::testReplace() {
  CPPUNIT_ASSERT_EQUAL(string("abc\n"), Util::replace("abc\r\n", "\r", ""));
  CPPUNIT_ASSERT_EQUAL(string("abc"), Util::replace("abc\r\n", "\r\n", ""));
  CPPUNIT_ASSERT_EQUAL(string(""), Util::replace("", "\r\n", ""));
  CPPUNIT_ASSERT_EQUAL(string("abc"), Util::replace("abc", "", "a"));
  CPPUNIT_ASSERT_EQUAL(string("xbc"), Util::replace("abc", "a", "x"));
}
