function Entity(img, n1)
   local self = {}
   self.ptr = new_entity(img,n1)


   function self.get_pos()
      self.x,self.y,self.z = entity_get_position(self.ptr)
      return self.x,self.y,self.z
   end

   self.get_pos()

   function self.get_name()
      return entity_get_name(self.ptr)
   end

   function self.set_pos(x,y,z)
      entity_set_position(self.ptr, x,y,z)
      self.x = x
      self.y = y
      self.z = z
   end

   function self.translate(dx,dy,dz)
      entity_translate(self.ptr, dx,dy,dz)
      self.x = self.x + dx
      self.y = self.y + dy
      self.z = self.z + dz
   end

   function self.get_pos()
      self.x,self.y,self.z = entity_get_position(self.ptr)
      return self.x,self.y,self.z
   end
   function self.get_x()
      return entity_get_x(self.ptr)
   end
   
   
   return self
end
