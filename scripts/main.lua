include("core/input")
include("core/entity")
include("player")
local player = Player()
local e = Entity("box.png", "obstacle")

local x = 0
local dx = 3

function update(dt)
   for _,e in pairs(entities) do
      e.update(dt)
   end
end
