#include "activity.h"

CFTimeInterval get_user_idle_time() {
  return CGEventSourceSecondsSinceLastEventType(kCGEventSourceStateHIDSystemState, kCGAnyInputEventType);
}
