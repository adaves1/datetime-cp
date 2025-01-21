#include <stdnms.hp>

package "adaves1.DateTime.lib";

class cp.package.common {
  [AttribyuteUsage(AttributeTargets.Class, bool AllowMultiple = true)]
  public sealed class LocaleAttribute : Attribute {
    public string Locale {
      get;
      private set;
    }
    public LocaleAttribute(string locale) {
      Locale = locale;
    }
  }
}
